/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 * @flow
 */

import React, { Component } from 'react';
import { AppRegistry, Text } from 'react-native';
import App from './components/app';


console.log("some message");


export default class flexTest extends Component {

  render() {

    return (
      <App />
    );
  }
}

AppRegistry.registerComponent('Examples', () => flexTest);
