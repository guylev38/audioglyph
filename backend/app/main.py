from fastapi import FastAPI
from fastapi.middleware.cors import CORSMiddleware

from app.api.routes import api_router

app = FastAPI(
    title="Audioglyph API",
    version="1.0.0",
    description="Backend for the Audioglyph audiobook manager.",
)

# In dev, the Vite server (http://localhost:5173) calls us through the
# Vite proxy at /api, so CORS is not strictly required. We allow it anyway
# to make curl / external clients during development painless.
app.add_middleware(
    CORSMiddleware,
    allow_origins=[
        "http://localhost:5173",
        "http://127.0.0.1:5173",
    ],
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

# All routes live under /api — see app/api/routes/__init__.py
app.include_router(api_router, prefix="/api")
