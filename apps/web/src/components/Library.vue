<script lang="ts" setup>
const items = [
  {
    title: "Book 1",
    value: 1,
  },
  {
    title: "Book 2",
    value: 1,
  },
  {
    title: "Book 3",
    value: 3,
  },
  {
    title: "Book 3",
    value: 3,
  },
  {
    title: "Book 3",
    value: 3,
  },

  {
    title: "Book 3",
    value: 3,
  },

  {
    title: "Book 3",
    value: 3,
  },

  {
    title: "Book 3",
    value: 3,
  },

  {
    title: "Book 3",
    value: 3,
  },
];
</script>

<template>
  <v-container>
    <v-container
      style="display: flex; flex-direction: row; justify-content: space-between"
    >
      <h2>Your Books</h2>
      <v-btn>
        <v-icon>mdi-plus</v-icon>
      </v-btn>
    </v-container>
    <v-list>
      <v-list-item v-for="item in items" :key="item.title" :title="item.title">
        <template v-slot:prepend>
          <v-avatar color="blue-lighten-1">
            <v-icon color="white"> mdi-book </v-icon>
          </v-avatar>
        </template>

        <template v-slot:append>
          <v-btn>
            <v-icon> mdi-dots-vertical </v-icon>
          </v-btn>
        </template>
      </v-list-item>
    </v-list>
  </v-container>
</template>
