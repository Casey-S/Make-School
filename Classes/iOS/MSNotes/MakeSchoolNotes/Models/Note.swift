//
//  Note.swift
//  MakeSchoolNotes
//
//  Created by MacBook Pro  on 10/14/16.
//  Copyright © 2016 MakeSchool. All rights reserved.
//

//import Foundation
//
//class Note {
//    var title = ""
//    var content = ""
//    var modificationTime = Date()
//}
//
import CoreData
import UIKit

class Note: NSManagedObject {
    @NSManaged public var title: String?
    @NSManaged public var content: String?
    @NSManaged public var modificationTime: Date?
    convenience init() {
        let appDelegate =   UIApplication.shared.delegate as! AppDelegate
        let persistentContainer = appDelegate.persistentContainer
        let managedContext = persistentContainer.viewContext
        let entity = NSEntityDescription.entity(forEntityName: "Note", in: managedContext)
        self.init(entity: entity!, insertInto: managedContext)
    }
}
