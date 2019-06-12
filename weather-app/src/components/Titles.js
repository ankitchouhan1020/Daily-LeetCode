import React, { Component } from 'react';

class Titles extends Component {
    render() {
        return (
            <div>
                <h1 className='title-container__title'>Weather App</h1>
                <h3 className='title-container__subtitle'>Find temperature,humidity</h3>
            </div>
        );
    }
};

export default Titles;
