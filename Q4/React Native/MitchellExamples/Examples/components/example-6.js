import React from 'react';
import { View, Text, StyleSheet } from 'react-native';

const Example6 = (props) => {
  return (
    <View style={styles.container}>
      <View style={[styles.box, styles.firstBox]} />
      <View style={[styles.box, styles.a, styles.secondBox]} />
      <View style={[styles.box, styles.b]} />
    </View>
  );
}

export default Example6;

const styles = StyleSheet.create({
  container: {
    flexDirection: 'row',
    flexWrap: 'wrap',
    flex: 1,
    justifyContent: 'space-around',
    alignItems: 'stretch'
  },
  box: {
    flex: 3,
    backgroundColor: '#f0f',
    margin: 10
  },
  firstBox: {
    flex: 1
  },
  secondBox: {
    flex: 2
  },
  a: {
    backgroundColor: '#0f0'
  },
  b: {
    backgroundColor: '#0ff'
  },
  c: {
    backgroundColor: '#ff0'
  },
  d: {
    backgroundColor: '#0f0'
  }
});
