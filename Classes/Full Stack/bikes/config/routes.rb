Rails.application.routes.draw do
  get 'bikes/index'

  get 'bikes/show'

  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
get '/bikes/:id', to: 'bikes#show'
get '/bikes', to: 'bikes#index'


end
