import React, { component } from 'react';
import { Text, View, Stylesheet } from 'react-native';

class TitleBar2 extends Component {
    constructor(props) {
        super(props);
    }
    render() {
        return (
            <View>
                <Text>{this.props.title}</Text>
            </View>
        );
    }
}
export default TitleBar2;

const styles = StyleSheet.create({

});
