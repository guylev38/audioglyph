<script setup lang="ts">
import HealthCheck from '@/components/HealthCheck.vue'
</script>

<template>
  <main class="app">
    <header>
      <h1>Audioglyph</h1>
      <p class="tagline">FOSS &amp; self-hosted audiobook management</p>
    </header>

    <section class="card">
      <h2>Backend health</h2>
      <HealthCheck />
    </section>
  </main>
</template>

<style scoped>
.app {
  max-width: 720px;
  margin: 4rem auto;
  padding: 0 1.5rem;
  font-family: system-ui, -apple-system, 'Segoe UI', sans-serif;
}

header {
  margin-bottom: 2rem;
}

header h1 {
  margin: 0;
  font-size: 2.5rem;
  letter-spacing: -0.02em;
}

.tagline {
  color: #666;
  margin: 0.25rem 0 0;
}

.card {
  padding: 1.5rem;
  border: 1px solid #e5e5e5;
  border-radius: 12px;
  background: #fafafa;
}

.card h2 {
  margin: 0 0 1rem;
  font-size: 1.125rem;
}
</style>
