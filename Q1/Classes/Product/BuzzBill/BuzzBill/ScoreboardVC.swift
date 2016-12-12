//
//  ScoreboardVC.swift
//  BuzzBill
//
//  Created by William Wold on 10/31/16.
//  Copyright © 2016 twof. All rights reserved.
//

import UIKit

class RepCell: UITableViewCell {
	
	var rep: RepModel?
	@IBOutlet weak var nameLabel: UILabel!
	@IBOutlet weak var picture: UIImageView!
	@IBOutlet weak var agreeLabel: UILabel!
	
	func setRep(repIn: RepModel) {
		
		rep=repIn
		
		nameLabel.text=rep?.getFullName() ?? "NO_REP"
		if rep!.totalBills==0 {
			agreeLabel.text = "No bills yet"
		}
		else {
			agreeLabel.text = "\(rep!.agreeBills)/\(rep!.totalBills) (\(rep!.agreeBills*100/rep!.totalBills)%)"
		}
		
		picture.image=rep!.picture
		picture.layer.cornerRadius = 40
		picture.layer.borderWidth = 4
		picture.layer.borderColor = rep!.agreeColor.cgColor
	}
}

class ScoreboardVC: UIViewController, UITableViewDataSource, UITableViewDelegate {
	
	@IBOutlet weak var tableView: UITableView!
	
	private var repProfileToView: RepModel?
	
	override func viewDidLoad() {
		super.viewDidLoad()
		
	}
	
	override func viewWillAppear(_ animated: Bool) {
		super.viewWillAppear(animated)
		
		RepModel.repUpdatedCallback = { (rep: RepModel) -> () in
			self.tableView.reloadData()
		}
	}
	
	public func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
		return representatives.count
	}
	
	public func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
		
		let cell = tableView.dequeueReusableCell(withIdentifier: "repTableCell") as! RepCell
		
		cell.setRep(repIn: representatives[indexPath.row])
		
		return cell
	}
	
	func tableView(_ tableView: UITableView, shouldHighlightRowAt indexPath: IndexPath) -> Bool {
		
		repProfileToView = representatives[indexPath.row]
		performSegue(withIdentifier: "showRepProfileSegue", sender: self)
		return false
	}
	
	override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
		if (segue.identifier=="showRepProfileSegue") {
			let target = segue.destination as! RepProfileVC
			if let rep = repProfileToView{
				target.rep=rep
			}
		}
	}
}
