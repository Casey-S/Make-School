//Using Gian's original Shopping Cart as an example.
//Fat arrow.

main() {
    var shoppingCart = []

    shoppingCart = add(shoppingCart)
    console.log(shoppingCart)

    shoppingCart = remove(shoppingCart)
    console.log(shoppingCart)

    writeDescription(shoppingCart)
}

add = (shoppingCart) => {
    shoppingCart.push( {id:1, name:'Pencil', price:1.99, quantity:1} );
    shoppingCart.push( {id:1, name:'Pencil', price:1.99, quantity:1} );
    shoppingCart.push( {id:2, name:'Apple', price:0.99, quantity:1} );
    shoppingCart.push( {id:3, name:'Banana', price:1.10, quantity:1} );
    shoppingCart.push( {id:4, name:'Shoe', price:11.99, quantity:1} );

    return shoppingCart
}

remove = (shoppingCart) => {
    for (object in shoppingCart) {
        console.log(object.id)
        if(object.id === 3) {
            console.log("entered")
            index = shoppingCart.indexOf(object)
            shoppingCart.splice(index, 1)
        }
    }

    return shoppingCart
}

writeDescription = (shoppingCart) => {
    for (object in shoppingCart) {
        console.log(object.name, object.price, object.quantity)
    }
}

totalCost = (shoppingCart) => {
    var total = 0

    for (object in shoppingCart) {
        total += object.price
    }

    console.log("total price = " + total)
}

main()
