json.extract! apartment, :id, :address, :description, :photo_url, :price, :created_at, :updated_at
json.url apartment_url(apartment, format: :json)