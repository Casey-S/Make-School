import React from 'react';
import { View, Text, StyleSheet } from 'react-native';

const Example10 = (props) => {
  var boxes = [];
  const abcd = ["a", "b", "c", "d"];
  for (var i = 0; i < 10; i++) {
    console.log(i % abcd.length);
    boxes.push(<View style={[styles.box, styles[abcd[i % abcd.length]]]} key={i} />);
  }

  return (
    <View style={styles.container}>
      {boxes}
    </View>
  );
}

export default Example10;

const styles = StyleSheet.create({
  container: {
    flex: 1,
    flexDirection: 'column',
    flexWrap: 'wrap',
    justifyContent: 'space-around',
    alignItems: 'flex-end'
  },
  box: {
    borderRadius: 10,
    backgroundColor: '#f0f',
    margin: 5
  },
  a: {
    backgroundColor: '#f0f',
    width: 50,
    height: 50
  },
  b: {
    backgroundColor: '#0f7',
    width: 60,
    height: 60
  },
  c: {
    backgroundColor: '#f84',
    width: 80,
    height: 80
  },
  d: {
    backgroundColor: '#f04',
    width: 120,
    height: 120
  }
});
