//
//  SummaryView.swift
//  BuzzBill
//
//  Created by fnord on 10/20/16.
//  Copyright © 2016 twof. All rights reserved.
//

import UIKit
import Alamofire
import SwiftyJSON

class SummaryView: UIViewController {
    @IBOutlet weak var billSummary: UITextView!
	@IBOutlet weak var titleLabel: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        Alamofire.request("https://congress.api.sunlightfoundation.com/bills?congress=113&history.enacted=true&apikey=56beeef0c5e34b939e93ac369ff28438&fields=summary,official_title").responseJSON { (responseData) -> Void in
            if((responseData.result.value) != nil) {
                let swiftyJsonVar = JSON(responseData.result.value!)
				print(swiftyJsonVar)
                self.billSummary.text = swiftyJsonVar["results"][0]["summary"].string
                self.titleLabel.text = swiftyJsonVar["results"][0]["official_title"].string
            }
        }
        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */

}
