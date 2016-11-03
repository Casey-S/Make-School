class Dog < ApplicationRecord
    validates :name, length: {minimum: 2, maximum: 10}
end
