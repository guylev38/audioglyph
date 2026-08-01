<script lang="ts">
export default { name: "AddBook" };
</script>

<script lang="ts" setup>
const addBookProps = defineProps<{ open: boolean }>();
</script>

<template>
  <v-dialog v-model="addBookProps.open"> </v-dialog>
</template>
