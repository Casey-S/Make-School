class CreateTransactions < ActiveRecord::Migration[5.0]
  def change
    create_table :transactions do |t|
      t.integer :from_user_id
      t.integer :to_user_id
      t.integer :status

      t.timestamps
    end
  end
end
