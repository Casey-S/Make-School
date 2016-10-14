require 'test_helper'

class PoliticiansControllerTest < ActionDispatch::IntegrationTest
  test "should get index" do
    get politicians_index_url
    assert_response :success
  end

end
