puts "Hello world"

animals = [ "tiger" ]
animals << "gorilla"
animals << "cat"

# symbol
# :apple

# hash
groceries = { "apples" => 3, "carrots" => 2 }
puts animals


def is_vowel?(char)
  # implicit return
  "aeiou".include? char
end

def count_vowels(sentence)

  vowel_count = 0

  sentence.each_char do |char|
    if is_vowel? char
      vowel_count += 1
    end
  end

  return vowel_count
end

sentence = "Hello world"
count = count_vowels(sentence)
puts "There are #{count} vowels in the sentence: " + sentence
