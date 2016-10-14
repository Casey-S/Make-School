class BikesController < ApplicationController
  def index
      @bike = Bike.all
  end

  def show
      bike_id = params[:id]

  end
end
