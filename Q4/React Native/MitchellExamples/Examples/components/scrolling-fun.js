import React from 'react';
import { ScrollView, View, StyleSheet } from 'react-native';

const ScrollingFun = (props) => {

    var array = [];
    for (var i = 0; i < 20; i++) {
        array.push(<View style={styles.box} />);
    }

    return (
        <ScrollView style={styles.container}>
            {array}
        </ScrollView>
    );
}

export default ScrollingFun;

const styles = StyleSheet.create({
    container: {
        flex: 1
    },
    box: {
        height: 100,
        margin: 5,
        backgroundColor: 'red',
        borderRadius: 10
    }
});
