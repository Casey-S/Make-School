import React from 'react';
import { View, Text, StyleSheet } from 'react-native';

const Example5 = (props) => {
  return (
    <View style={styles.container}>
      <View style={[styles.box]} />
      <View style={[styles.box, styles.a]} />
      <View style={[styles.box, styles.b]} />
    </View>
  );
}

export default Example5;

const styles = StyleSheet.create({
  container: {
    flexDirection: 'row',
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
  a: {
    backgroundColor: '#0f0'
  },
  b: {
    backgroundColor: '#0ff'
  }
});
