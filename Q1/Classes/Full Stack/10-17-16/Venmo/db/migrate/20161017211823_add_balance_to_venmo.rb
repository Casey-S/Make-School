class AddBalanceToVenmo < ActiveRecord::Migration[5.0]
  def change
    add_column :users, :balance, :double
  end
end
