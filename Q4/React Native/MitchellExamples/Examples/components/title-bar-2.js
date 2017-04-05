import React, { Component } from 'react';
import { Text, View, StyleSheet } from 'react-native';

class TitleBar2 extends Component {
    constructor(props) {
        super(props);
    }
    render() {
        return (
            <View style={styles.container}>
                <Text>{this.props.title}</Text>
            </View>
        );
    }
}
export default TitleBar2;

const styles = StyleSheet.create(
    {

        container: {
            height: 60,
            //flex: 1,
            backgroundColor: "blue",
            justifyContent: 'center',
            flexDirection: 'column'
        }

    }
);
