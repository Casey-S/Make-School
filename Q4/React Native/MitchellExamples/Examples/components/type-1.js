import React from 'react';
import { View, Text, StyleSheet } from 'react-native';

const Example9 = (props) => {
  return (
    <View style={styles.container}>
      <Text style={[styles.type, styles.a]}>Hello</Text>
      <Text style={[styles.type, styles.b]}>World</Text>
    </View>
  );
}

export default Example9;

const styles = StyleSheet.create({
  container: {
    flex: 1,
    flexDirection: 'column',
    justifyContent: 'space-around',
    alignItems: 'center'
  },
  type: {
    flex: 1,
    textAlign: 'center'
  },
  a: {
    backgroundColor: '#f00',
    fontSize: 80,
    marginTop: 20
  },
  b: {
    backgroundColor: '#0f0',
    fontSize: 40
  }
});
