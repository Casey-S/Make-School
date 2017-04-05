import React from 'react';
import { View, Text, StyleSheet } from 'react-native';

const Example9 = (props) => {
  return (
    <View style={styles.container}>
      <View style={styles.box} />
      <View style={[styles.box, styles.a, styles.subContainer]}>
        <View style={[styles.box, styles.e]} />
        <View style={[styles.box, styles.f]} />
      </View>
      <View style={[styles.box, styles.b]} />
      <View style={[styles.box, styles.c]} />
    </View>
  );
}

export default Example9;

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
  subContainer: {
    flexDirection: 'row',
  },
  a: {backgroundColor: '#08f'},
  b: {backgroundColor: '#0ff'},
  c: {backgroundColor: '#ff0'},
  d: {backgroundColor: '#0f0'},
  e: {backgroundColor: '#f00', flex: 1},
  f: {backgroundColor: '#0f0', flex: 3},
  g: {backgroundColor: '#00f'}
});
