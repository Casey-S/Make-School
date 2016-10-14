class CreateBikes < ActiveRecord::Migration[5.0]
  def change
    create_table :bikes do |t|
      t.string :make
      t.string :model
      t.decimal :price

      t.timestamps
    end
  end
end
