//
//  SunlightHelper.swift
//  BuzzBill
//
//  Created by William Wold on 10/31/16.
//  Copyright © 2016 twof. All rights reserved.
//

import Foundation
import Alamofire
import SwiftyJSON

let apiKey="56beeef0c5e34b939e93ac369ff28438"

func launchURL(url: String) {
	
	UIApplication.shared.open(URL(string: url)!, options: [:]) { (input: Bool) in
		
	}
}

func getDataFromUrl(url: URL, completion: @escaping (_ data: Data?, _  response: URLResponse?, _ error: Error?) -> Void) {
	URLSession.shared.dataTask(with: url) {
		(data, response, error) in
		completion(data, response, error)
		}.resume()
}

func getImageFromURL(url: String, callback: @escaping (UIImage) -> ()) {
	
	getDataFromUrl(url: URL(string: url)!) { (data, response, error)  in
		if error != nil {
			print("\n\n\nimage downloading error: \(error.debugDescription)\n\n\n")
			return
		}
		
		guard let data = data else
		{
			print("\n\n\nno image data\n\n\n")
			return
		}
		
		DispatchQueue.main.async() { () -> Void in
			if let image = UIImage(data: data) {
				callback(image)
				
			}
		}
	}
}

func getRepsFor(zip: String, callback: @escaping ([RepModel])->())
{
	let requestURL = "https://congress.api.sunlightfoundation.com/legislators/locate?zip=\(zip)&apikey=\(apiKey)"
	
	Alamofire.request(requestURL).responseJSON { (responseData) in
		
		if let responseVal = responseData.result.value {
			
			let jsonData = JSON(responseVal)
			var out = [RepModel]()
			
			for i in jsonData["results"] {
				
				let rep = RepModel(jsonData: i.1)
				
				out.append(rep)
			}
			
			callback(out)
		}
		else {
			print("\n\n\ncould not download rep data\n\n\n")
		}
	}
}

