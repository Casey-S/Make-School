require 'test_helper'

class PoliticianControllerTest < ActionDispatch::IntegrationTest
  test "should get index" do
    get politician_index_url
    assert_response :success
  end

  test "should get show" do
    get politician_show_url
    assert_response :success
  end

end
