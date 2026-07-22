// API response shapes — mirror backend/app/api/routes/*.py
// Keeping them here (rather than a generated client) is fine while the
// surface is small. If this grows, switch to an OpenAPI generator.

export interface HealthResponse {
  status: string
  service: string
}
