/**
 * Sample React Native App
 * https://github.com/facebook/react-native
 * @flow
 */

import React, { Component } from 'react';
import { AppRegistry } from 'react-native';
import InClass from "./components/in-class"

export default class ClassFlexBox extends Component {
  render() {
    return (
        <InClass/>
    );
  }
}

AppRegistry.registerComponent('ClassFlexBox', () => ClassFlexBox);
