require 'test_helper'

class DogTest < ActiveSupport::TestCase
  def setup
    @dog = Dog.new(name: "Doge", breed: "Meme", favorite_park: "4chan")
  end

  test "should be valid" do
    @dog.valid
  end

  test "name should not be too short" do
    @dog.name = "A"
    assert_not @dog.valid?
  end

  test "name should not be too long" do
    @dog.name = "This is an insanely long politician name"
    assert_not @dog.valid?
  end
end
