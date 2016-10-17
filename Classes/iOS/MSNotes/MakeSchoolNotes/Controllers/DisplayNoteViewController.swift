//
//  DisplayNoteViewController.swift
//  MakeSchoolNotes
//
//  Created by Chris Orcutt on 1/10/16.
//  Copyright © 2016 MakeSchool. All rights reserved.
//

import UIKit

class DisplayNoteViewController: UIViewController {
    
    var note: Note?
    
    
    @IBOutlet weak var noteTitleTextField: UITextField!
    @IBOutlet weak var noteContentTextView: UITextView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        // 1
        if let note = note {
            // 2
            noteTitleTextField.text = note.title
            noteContentTextView.text = note.content
        } else {
            // 3
            noteTitleTextField.text = ""
            noteContentTextView.text = ""
        }
    }
    
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        if segue.identifier == "Save" {
            // if note exists, update title and content
            let note = self.note ?? Note()
            note.title = noteTitleTextField.text ?? ""
            note.content = noteContentTextView.text ?? ""
            note.modificationTime = Date()
            CoreDataHelper.saveNote()
        }
    }
}
