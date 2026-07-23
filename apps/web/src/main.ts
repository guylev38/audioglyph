import { createApp } from 'vue'
import { createVuetify } from 'vuetify'
import 'vuetify/styles'
import '@mdi/font/css/materialdesignicons.css'

import App from './App.vue'
import './style.css'

const vuetify = createVuetify({
    theme:{
        defaultTheme: 'dark',
        themes:{
            light: {dark: false, colors: {}},
            dark: {dark: true, colors: {}}
        }
    }
})

createApp(App).use(vuetify).mount('#app')
