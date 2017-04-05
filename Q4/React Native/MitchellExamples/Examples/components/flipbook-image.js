import React from 'react';
import { ScrollView, View, StyleSheet, Image } from 'react-native';

const FlipbookImage = (props) => {
    return (
        <View>
            <Image source={require(props.fileName)} />
        </View>
    );
};
