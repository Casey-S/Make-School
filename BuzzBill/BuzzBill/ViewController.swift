//
//  ViewController.swift
//  BuzzBill
//
//  Created by fnord on 10/18/16.
//  Copyright © 2016 twof. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var fiscalBillView: UIView!
    @IBOutlet weak var parksAndRecBillView: UIView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
    }
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func unwindToMenu(segue: UIStoryboardSegue) {}

}

