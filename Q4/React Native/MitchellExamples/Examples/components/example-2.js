import React from 'react';
import { View, Text, StyleSheet } from 'react-native';

const Example2 = (props) => {
  return (
    <View style={styles.container}>
      <View style={[styles.box, styles.firstBox]} />
      <View style={[styles.box, styles.a]} />
      <View style={[styles.box, styles.b]} />
      <View style={[styles.box, styles.c]} />
    </View>
  );
}

export default Example2;

const styles = StyleSheet.create({
  container: {
    flexDirection: 'column',
    flexWrap: 'wrap',
    flex: 1,
    justifyContent: 'space-around',
    alignItems: 'stretch'
  },
  box: {
    flex: 1,
    backgroundColor: '#f0f',
    margin: 10
  },
  firstBox: {
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
