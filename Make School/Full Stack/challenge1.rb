stringIn = "this is a test"
# stringIn.split
#ary = [stringIn.split]
#puts ary

result = stringIn.split.map(&:capitalize).join(' ')
puts result

newSentence = "dicks out for harambe"
newWorldHarambe = newSentence.split.map(&:capitalize).join(' ')
puts newWorldHarambe

dicksOut = "for harambe"
harambeStepOne = dicksOut.split
harambeStepTwo = harambeStepOne.map(&:capitalize)
harambeStepThree = harambeStepTwo.join(' ')

puts harambeStepThree
