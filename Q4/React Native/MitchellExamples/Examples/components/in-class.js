import React from 'react';
import { View, StyleSheet } from 'react-native';

const InClass = (props) => {
  return (
    <View style={styles.container}>
      <View style={[styles.box, styles.a]}></View>
      <View style={[styles.box, styles.b]}>
        <View style={styles.e} />
        <View style={styles.f} />
      </View>
      <View style={[styles.box, styles.c]}></View>
      <View style={[styles.box, styles.d]}></View>
    </View>
  );
}
export default InClass;
const styles = StyleSheet.create({
  container: {
    flex: 1,
    flexDirection: 'column',
    backgroundColor: '#f00'
  },
  box: {
    flex: 1,
    margin: 5,
    backgroundColor: '#0f0',
  },
  a: {backgroundColor: '#0f0', flex: 2},
  b: {backgroundColor: '#00f', flex: 0.5, flexDirection:'row'},
  c: {backgroundColor: '#f0f'},
  d: {backgroundColor: '#ff0'},
  e: {backgroundColor: '#0ff', flex: 1, margin: 5},
  f: {backgroundColor: '#ff0', flex: 2}
});







//
