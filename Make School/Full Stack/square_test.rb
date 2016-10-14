class TestSquare < Minitest::test
    def setup
    end

    def test_valid
        valid_square = Square.new([2,2,2,2])
        assert valid_square.valid?, "square detected as invalid"

        invalid_square = Square.new([2,1,2,2])
        assert !invalid_square.valid?, "square detected as valid"
    end
end
