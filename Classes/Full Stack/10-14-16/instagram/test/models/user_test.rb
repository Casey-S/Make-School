require 'test_helper'

class UserTest < ActiveSupport::TestCase
  # test "the truth" do
  #   assert true
  # end
  def setup
      @user = User.new(name:"Casey", handle:"CaseyMane")
  end
  test "can look up associated photos" do
      photo = Photo.new(user:@user)
      photo.users = @user
      photo.save

      assert_equal 1, @user.photos.size
  end

end
