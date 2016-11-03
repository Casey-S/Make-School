class User < ApplicationRecord

    validates :name, length: { maximum: 20, minimum: 2 }

    # has_many :photos
end
