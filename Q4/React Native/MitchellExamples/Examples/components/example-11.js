import React from 'react';
import { View, Text, StyleSheet } from 'react-native';

const Example11 = (props) => {
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

export default Example11;

const styles = StyleSheet.create({
  container: {
    flex: 1,
    flexDirection: 'column',
  },
  box: {
    borderRadius: 10,
    backgroundColor: '#f0f',
    margin: 5
  },
  a: {
    backgroundColor: '#f0f',
    flex: 1
  },
  b: {
    backgroundColor: '#0f7',
    flex: 2
  },
  c: {
    backgroundColor: '#f84',
    flex: 3
  },
  d: {
    backgroundColor: '#f04',
    flex: 2
  }
});
