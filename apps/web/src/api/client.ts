// Thin typed wrapper around fetch for our /api/* endpoints.
// In dev, Vite proxies /api → http://localhost:8000 (see vite.config.ts).
// In prod, the reverse proxy does the same.

const baseUrl = import.meta.env.VITE_API_BASE_URL ?? '/api'

export async function apiGet<T>(path: string): Promise<T> {
  const url = `${baseUrl}${path.startsWith('/') ? path : `/${path}`}`
  const res = await fetch(url, { method: 'GET' })

  if (!res.ok) {
    throw new Error(`GET ${url} failed: ${res.status} ${res.statusText}`)
  }

  return (await res.json()) as T
}
