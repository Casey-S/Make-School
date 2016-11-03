class CreateApartments < ActiveRecord::Migration[5.0]
  def change
    create_table :apartments do |t|
      t.string :address
      t.string :description
      t.string :photo_url
      t.decimal :price

      t.timestamps
    end
  end
end
