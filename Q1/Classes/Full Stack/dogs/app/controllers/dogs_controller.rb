class DogsController < ApplicationController
  def index
      @dogs=Dog.all
  end

  def new
      @dog = Dog.new
    end

    def show
      @dog = Dog.find(params[:id])
    end

    def create
        dog_params = params.require(:dog).permit(:name, :breed, :favorite_park)
      dog = Dog.create(dog_params)
      redirect_to dogs_path
    end

end
