from fastapi import APIRouter

from app.api.routes import health

# All route modules are aggregated here. Mount this with the `/api` prefix
# in `app.main` so every endpoint lives under /api/*.
api_router = APIRouter()
api_router.include_router(health.router)
