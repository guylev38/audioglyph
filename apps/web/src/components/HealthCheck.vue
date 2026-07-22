<script setup lang="ts">
import { onMounted, ref } from 'vue'

import { apiGet } from '@/api/client'
import type { HealthResponse } from '@/types/api'

const data = ref<HealthResponse | null>(null)
const error = ref<string | null>(null)
const loading = ref(true)

onMounted(async () => {
  try {
    data.value = await apiGet<HealthResponse>('/health')
  } catch (e) {
    error.value = e instanceof Error ? e.message : String(e)
  } finally {
    loading.value = false
  }
})
</script>

<template>
  <div v-if="loading" class="muted">Checking backend…</div>
  <div v-else-if="error" class="error">⚠ {{ error }}</div>
  <dl v-else class="kv">
    <dt>status</dt>
    <dd><code>{{ data?.status }}</code></dd>
    <dt>service</dt>
    <dd><code>{{ data?.service }}</code></dd>
  </dl>
</template>

<style scoped>
.muted { color: #888; }
.error { color: #b91c1c; }
.kv {
  display: grid;
  grid-template-columns: max-content 1fr;
  gap: 0.25rem 1rem;
  margin: 0;
}
.kv dt { color: #666; }
.kv dd { margin: 0; }
code {
  background: #fff;
  padding: 0.125rem 0.4rem;
  border-radius: 4px;
  border: 1px solid #e5e5e5;
}
</style>
