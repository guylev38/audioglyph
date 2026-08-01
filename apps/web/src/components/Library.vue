<script lang="ts" setup>
import { ref, type Ref } from "vue";
import AddBook from "./forms/AddBook.vue";

const books = [
  {
    title: "Book 1",
    value: 1,
  },
  {
    title: "Book 2",
    value: 2,
  },
];

const bookOptions = [
  { title: "Edit", prependIcon: "mdi-pencil", code: "book-edit" },
  { title: "Remove", prependIcon: "mdi-trash-can", code: "book-delete" },
];

const addBookOpen: Ref<boolean> = ref(false);
</script>

<template>
  <v-container>
    <v-container
      style="display: flex; flex-direction: row; justify-content: space-between"
    >
      <h2>Your Books</h2>
      <v-btn color="green-darken-1">
        <v-icon>mdi-plus</v-icon>
      </v-btn>
    </v-container>
    <v-list>
      <v-list-item
        v-for="book in books"
        :key="book.title"
        :title="book.title"
        style="padding: 10px"
      >
        <template v-slot:prepend>
          <v-avatar color="blue-darken-1">
            <v-icon color="white"> mdi-book </v-icon>
          </v-avatar>
        </template>
        <template v-slot:append>
          <v-menu location="bottom">
            <template v-slot:activator="{ props }">
              <v-btn v-bind="props">
                <v-icon> mdi-dots-vertical </v-icon>
              </v-btn>
            </template>
            <v-list>
              <v-list-item
                v-for="(option, index) in bookOptions"
                :key="index"
                :value="index"
              >
                <v-list-item-title style="font-size: small">
                  <v-icon size="20px"> {{ option.prependIcon }}</v-icon>
                  {{ option.title }}
                </v-list-item-title>
              </v-list-item>
            </v-list>
          </v-menu>
        </template>
      </v-list-item>
    </v-list>
  </v-container>
</template>
