# audioglyph

FOSS & self hosted audiobook management software.

---

## Development setup

Monorepo with a **Vue 3 + TypeScript** frontend and a **FastAPI** (Python) backend.

### Layout

```
audioglyph/
├── apps/
│   └── web/        # Vue 3 + TS, served by Vite (port 5173)
└── backend/        # FastAPI + uv, served by Uvicorn (port 8000)
```

The pnpm workspace only manages `apps/*` — `backend/` is a standalone Python project (uv). A root `pnpm dev` script starts both servers together via `concurrently`.

### Prerequisites

- **Node.js** ≥ 20
- **pnpm** ≥ 9 (`npm install -g pnpm`)
- **uv** ≥ 0.4 ([install](https://docs.astral.sh/uv/getting-started/installation/))
- **Python** 3.12 (managed automatically by uv if it's installed)

### Quick start

```bash
# 1. Install JS dependencies (links the pnpm workspace)
pnpm install

# 2. Install Python dependencies (creates backend/.venv)
pnpm run api:install

# 3. Start both dev servers
pnpm dev
```

Then open:

| URL                              | What                              |
| -------------------------------- | --------------------------------- |
| http://localhost:5173            | Vue app (proxies `/api` → 8000)   |
| http://localhost:8000/api/health | Backend health endpoint           |
| http://localhost:8000/docs        | FastAPI interactive Swagger UI    |

### Common commands

```bash
pnpm dev              # web + api together (concurrently)
pnpm dev:web          # only the Vite dev server
pnpm dev:api          # only the Uvicorn dev server
pnpm build            # build the web app for production
pnpm preview          # preview the production web build
pnpm run api:install  # uv sync (re-install Python deps)
```

### How the frontend talks to the backend

In dev, the Vue app uses **no CORS configuration** — it calls relative URLs like `/api/health`, and Vite's dev server proxies them to `http://localhost:8000`. The proxy is defined in `apps/web/vite.config.ts`.

For production, point your reverse proxy (Nginx, Caddy, the cloud platform, etc.) at `/api` → the FastAPI service the same way.

### Conventions

- **TypeScript everywhere** in `apps/` (strict mode via `@vue/tsconfig/tsconfig.dom.json`).
- **Python 3.12** pinned via `backend/.python-version`.
- **`uv` for Python deps** — never `pip install` directly. Run `uv add <pkg>` to add a dependency; this updates `pyproject.toml` and `uv.lock`.
- **All API routes live under `/api`** — keep new endpoints inside `backend/app/api/routes/` and include them in the aggregator there.
