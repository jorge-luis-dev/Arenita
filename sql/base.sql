--
-- PostgreSQL database cluster dump
--

-- Started on 2017-01-04 18:38:45 ECT

SET default_transaction_read_only = off;

SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;

--
-- Roles
--

CREATE ROLE postgres;
ALTER ROLE postgres WITH SUPERUSER INHERIT CREATEROLE CREATEDB LOGIN REPLICATION BYPASSRLS;






--
-- Database creation
--

REVOKE CONNECT,TEMPORARY ON DATABASE template1 FROM PUBLIC;
GRANT CONNECT ON DATABASE template1 TO PUBLIC;


\connect postgres

SET default_transaction_read_only = off;

--
-- PostgreSQL database dump
--

-- Dumped from database version 9.6.1
-- Dumped by pg_dump version 9.6.1

-- Started on 2017-01-04 18:38:45 ECT

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;
SET row_security = off;

--
-- TOC entry 2374 (class 1262 OID 12408)
-- Dependencies: 2373
-- Name: postgres; Type: COMMENT; Schema: -; Owner: postgres
--

COMMENT ON DATABASE postgres IS 'default administrative connection database';


--
-- TOC entry 1 (class 3079 OID 12394)
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- TOC entry 2376 (class 0 OID 0)
-- Dependencies: 1
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET search_path = public, pg_catalog;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- TOC entry 185 (class 1259 OID 16445)
-- Name: adm_entidades; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE adm_entidades (
    id integer NOT NULL,
    documento character varying(10) NOT NULL,
    tipo_documento character varying(10) NOT NULL,
    nombre character varying(100) NOT NULL,
    apellido character varying(100) NOT NULL,
    razon_social character varying(200) NOT NULL,
    direccion character varying(500),
    telefono character varying(50),
    correo_electronico character varying(50),
    estado character varying(10) DEFAULT 'Activo'::character varying NOT NULL,
    observacion character varying(100),
    id_entidad integer,
    id_localidad integer
);


ALTER TABLE adm_entidades OWNER TO postgres;

--
-- TOC entry 186 (class 1259 OID 16453)
-- Name: adm_localidades; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE adm_localidades (
    id integer NOT NULL,
    localidad character varying(50) NOT NULL,
    estado character varying(10) NOT NULL,
    observacion character varying(500),
    id_localidad integer NOT NULL
);


ALTER TABLE adm_localidades OWNER TO postgres;

--
-- TOC entry 188 (class 1259 OID 16471)
-- Name: adm_propiedad_entidades; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE adm_propiedad_entidades (
    id integer NOT NULL,
    id_entidad integer NOT NULL,
    tipo character varying(10),
    propiedad character varying(50) NOT NULL,
    valor character varying(10),
    estado character varying(10),
    observacion character varying(500)
);


ALTER TABLE adm_propiedad_entidades OWNER TO postgres;

--
-- TOC entry 187 (class 1259 OID 16461)
-- Name: adm_propiedades; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE adm_propiedades (
    tabla character varying(50),
    propiedad character varying(50) NOT NULL,
    observacion character varying(500),
    estado character varying(10) NOT NULL
);


ALTER TABLE adm_propiedades OWNER TO postgres;

--
-- TOC entry 189 (class 1259 OID 16479)
-- Name: adm_tipos; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE adm_tipos (
    tabla character varying(50),
    tipo character varying(50) NOT NULL,
    observacion character varying(500),
    estado character varying(10) NOT NULL
);


ALTER TABLE adm_tipos OWNER TO postgres;

--
-- TOC entry 2377 (class 0 OID 0)
-- Dependencies: 189
-- Name: COLUMN adm_tipos.tabla; Type: COMMENT; Schema: public; Owner: postgres
--

COMMENT ON COLUMN adm_tipos.tabla IS 'Nombre de la tabla a donde se aplica el tipo';


--
-- TOC entry 190 (class 1259 OID 16489)
-- Name: doc_documentos; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE doc_documentos (
    id integer NOT NULL,
    numero integer,
    id_transaccion integer NOT NULL,
    id_entidad integer NOT NULL,
    fecha date,
    usuario character varying(10),
    observacion character varying(100),
    estado character varying(10),
    id_documento integer NOT NULL,
    total numeric
);


ALTER TABLE doc_documentos OWNER TO postgres;

--
-- TOC entry 191 (class 1259 OID 16497)
-- Name: doc_documentos_detalle; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE doc_documentos_detalle (
    id integer NOT NULL,
    id_documento integer NOT NULL,
    linea integer,
    id_producto integer NOT NULL,
    unidad character varying(10) NOT NULL,
    id_inventario integer NOT NULL,
    cantidad numeric,
    precio numeric,
    precio_total numeric,
    unidad_alterna character varying(10),
    cantidad_alterna numeric,
    factor character varying(20),
    descuento numeric,
    impuesto numeric,
    observacion character varying(100),
    estado character varying(10)
);


ALTER TABLE doc_documentos_detalle OWNER TO postgres;

--
-- TOC entry 192 (class 1259 OID 16505)
-- Name: doc_transacciones; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE doc_transacciones (
    id integer NOT NULL,
    id_entidad integer NOT NULL,
    codigo integer,
    nombre character varying(100),
    numero_inicial integer,
    numero_actual integer,
    numero_final integer,
    tipo character varying(20),
    observacion character varying(100),
    estado character varying(10)
);


ALTER TABLE doc_transacciones OWNER TO postgres;

--
-- TOC entry 193 (class 1259 OID 16512)
-- Name: inv_bodegas; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE inv_bodegas (
    id integer NOT NULL,
    nombre character varying(100),
    observacion character varying(500),
    estado character varying(10),
    id_entidad integer NOT NULL
);


ALTER TABLE inv_bodegas OWNER TO postgres;

--
-- TOC entry 194 (class 1259 OID 16522)
-- Name: inv_grupos; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE inv_grupos (
    id integer NOT NULL,
    nombre character varying(200) NOT NULL,
    estado character varying(10) NOT NULL,
    observacion character varying(500),
    id_grupo integer NOT NULL
);


ALTER TABLE inv_grupos OWNER TO postgres;

--
-- TOC entry 195 (class 1259 OID 16530)
-- Name: inv_inventarios; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE inv_inventarios (
    id integer NOT NULL,
    id_bodega integer NOT NULL,
    id_tipo_inventario integer NOT NULL,
    nombre character varying(50),
    observacion character varying(100),
    estado character varying(10)
);


ALTER TABLE inv_inventarios OWNER TO postgres;

--
-- TOC entry 196 (class 1259 OID 16535)
-- Name: inv_movimientos; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE inv_movimientos (
    id integer NOT NULL,
    id_transaccion integer NOT NULL,
    fecha date,
    id_entidad integer NOT NULL,
    usuario character varying(10) NOT NULL,
    observacion character varying(100),
    estado character varying(10),
    tipo character varying(10),
    id_movimiento integer NOT NULL,
    total numeric,
    id_documento integer NOT NULL
);


ALTER TABLE inv_movimientos OWNER TO postgres;

--
-- TOC entry 197 (class 1259 OID 16543)
-- Name: inv_movimientos_detalle; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE inv_movimientos_detalle (
    id integer NOT NULL,
    id_movimiento integer NOT NULL,
    id_producto integer NOT NULL,
    unidad character varying(10) NOT NULL,
    linea integer,
    id_inventario integer NOT NULL,
    cantidad numeric NOT NULL,
    costo numeric,
    costo_total numeric,
    unidad_alterna character varying(10),
    cantidad_alterna numeric,
    factor character varying(20),
    obseravcion character varying(100),
    estado character varying(10)
);


ALTER TABLE inv_movimientos_detalle OWNER TO postgres;

--
-- TOC entry 198 (class 1259 OID 16551)
-- Name: inv_permisos_transaccion; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE inv_permisos_transaccion (
    id_trasaccion integer NOT NULL,
    usuario character varying(10) NOT NULL,
    observacion character varying(100),
    estado character varying(10)
);


ALTER TABLE inv_permisos_transaccion OWNER TO postgres;

--
-- TOC entry 199 (class 1259 OID 16554)
-- Name: inv_productos; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE inv_productos (
    id integer NOT NULL,
    nombre character varying(200) NOT NULL,
    codigo_barras character varying(200),
    unidad character varying(10) NOT NULL,
    id_grupo integer NOT NULL,
    tipo character varying(50) NOT NULL,
    estado character varying(10) NOT NULL,
    observacion character varying(500),
    id_entidad integer NOT NULL
);


ALTER TABLE inv_productos OWNER TO postgres;

--
-- TOC entry 200 (class 1259 OID 16564)
-- Name: inv_productos_inventario; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE inv_productos_inventario (
    id integer NOT NULL,
    id_producto integer NOT NULL,
    unidad character varying(10) NOT NULL,
    id_inventario integer NOT NULL
);


ALTER TABLE inv_productos_inventario OWNER TO postgres;

--
-- TOC entry 201 (class 1259 OID 16569)
-- Name: inv_propiedad_productos; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE inv_propiedad_productos (
    id_producto integer NOT NULL,
    unidad character varying(10) NOT NULL,
    propiedad character varying(50) NOT NULL,
    valor numeric(24,0) NOT NULL,
    estado character varying(10) NOT NULL,
    observacion character varying(500)
);


ALTER TABLE inv_propiedad_productos OWNER TO postgres;

--
-- TOC entry 202 (class 1259 OID 16577)
-- Name: inv_saldos_mensual; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE inv_saldos_mensual (
    id integer NOT NULL,
    id_productos integer NOT NULL,
    unidad character varying(10) NOT NULL,
    id_inventario integer NOT NULL,
    saldo numeric,
    "aÑo" character varying(10),
    mes character varying(10),
    fecha date
);


ALTER TABLE inv_saldos_mensual OWNER TO postgres;

--
-- TOC entry 203 (class 1259 OID 16585)
-- Name: inv_tipos_inventario; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE inv_tipos_inventario (
    id integer NOT NULL,
    nombre character varying(50),
    observacion character varying(50),
    estado character varying(1)
);


ALTER TABLE inv_tipos_inventario OWNER TO postgres;

--
-- TOC entry 204 (class 1259 OID 16590)
-- Name: inv_transacciones; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE inv_transacciones (
    id integer NOT NULL,
    tipo character varying(30),
    observacion character varying(100),
    estado character varying(10),
    id_entidad integer NOT NULL
);


ALTER TABLE inv_transacciones OWNER TO postgres;

--
-- TOC entry 206 (class 1259 OID 16603)
-- Name: inv_unidad_alternas; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE inv_unidad_alternas (
    id_producto integer NOT NULL,
    unidad character varying(10) NOT NULL,
    factor integer,
    unidad_alterna character varying(10) NOT NULL,
    estado character varying(10),
    observacion character varying(500)
);


ALTER TABLE inv_unidad_alternas OWNER TO postgres;

--
-- TOC entry 205 (class 1259 OID 16595)
-- Name: inv_unidades; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE inv_unidades (
    unidad character varying(10) NOT NULL,
    nombre character varying(200) NOT NULL,
    estado character varying(10) NOT NULL,
    observacion character varying(500)
);


ALTER TABLE inv_unidades OWNER TO postgres;

--
-- TOC entry 207 (class 1259 OID 16611)
-- Name: seg_menus; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE seg_menus (
    id integer NOT NULL,
    nombre character varying(200) NOT NULL,
    url character varying(500) NOT NULL,
    propiedad character varying(500) NOT NULL,
    observacion character varying(500),
    estado character varying(10) NOT NULL,
    id_menu integer NOT NULL
);


ALTER TABLE seg_menus OWNER TO postgres;

--
-- TOC entry 208 (class 1259 OID 16619)
-- Name: seg_permisos; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE seg_permisos (
    id integer NOT NULL,
    tipo_permiso character varying(50) NOT NULL,
    permiso character varying(10),
    usuario character varying(10) NOT NULL,
    id_menu integer NOT NULL,
    observacion character varying(500),
    estado character varying(10) NOT NULL
);


ALTER TABLE seg_permisos OWNER TO postgres;

--
-- TOC entry 2378 (class 0 OID 0)
-- Dependencies: 208
-- Name: COLUMN seg_permisos.tipo_permiso; Type: COMMENT; Schema: public; Owner: postgres
--

COMMENT ON COLUMN seg_permisos.tipo_permiso IS 'Lectura, escritura, actualización, etc';


--
-- TOC entry 2379 (class 0 OID 0)
-- Dependencies: 208
-- Name: COLUMN seg_permisos.permiso; Type: COMMENT; Schema: public; Owner: postgres
--

COMMENT ON COLUMN seg_permisos.permiso IS 'si, no';


--
-- TOC entry 209 (class 1259 OID 16627)
-- Name: seg_usuarios; Type: TABLE; Schema: public; Owner: postgres
--

CREATE TABLE seg_usuarios (
    usuario character varying(10) NOT NULL,
    tipo character varying(10),
    observacion character varying(500),
    estado character varying(10) DEFAULT 'Activo'::character varying NOT NULL,
    id_entidad integer NOT NULL,
    id integer NOT NULL
);


ALTER TABLE seg_usuarios OWNER TO postgres;

--
-- TOC entry 210 (class 1259 OID 16856)
-- Name: seg_usuarios_id_seq; Type: SEQUENCE; Schema: public; Owner: postgres
--

CREATE SEQUENCE seg_usuarios_id_seq
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER TABLE seg_usuarios_id_seq OWNER TO postgres;

--
-- TOC entry 2380 (class 0 OID 0)
-- Dependencies: 210
-- Name: seg_usuarios_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: postgres
--

ALTER SEQUENCE seg_usuarios_id_seq OWNED BY seg_usuarios.id;


--
-- TOC entry 2122 (class 2604 OID 16858)
-- Name: seg_usuarios id; Type: DEFAULT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY seg_usuarios ALTER COLUMN id SET DEFAULT nextval('seg_usuarios_id_seq'::regclass);


--
-- TOC entry 2343 (class 0 OID 16445)
-- Dependencies: 185
-- Data for Name: adm_entidades; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY adm_entidades (id, documento, tipo_documento, nombre, apellido, razon_social, direccion, telefono, correo_electronico, estado, observacion, id_entidad, id_localidad) FROM stdin;
1	1002456877	Cédula	Jorge	Quiguango	Jorge Quiguango	Ibarra	\N	\N	Activo	\N	\N	\N
\.


--
-- TOC entry 2344 (class 0 OID 16453)
-- Dependencies: 186
-- Data for Name: adm_localidades; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY adm_localidades (id, localidad, estado, observacion, id_localidad) FROM stdin;
\.


--
-- TOC entry 2346 (class 0 OID 16471)
-- Dependencies: 188
-- Data for Name: adm_propiedad_entidades; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY adm_propiedad_entidades (id, id_entidad, tipo, propiedad, valor, estado, observacion) FROM stdin;
\.


--
-- TOC entry 2345 (class 0 OID 16461)
-- Dependencies: 187
-- Data for Name: adm_propiedades; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY adm_propiedades (tabla, propiedad, observacion, estado) FROM stdin;
\.


--
-- TOC entry 2347 (class 0 OID 16479)
-- Dependencies: 189
-- Data for Name: adm_tipos; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY adm_tipos (tabla, tipo, observacion, estado) FROM stdin;
\.


--
-- TOC entry 2348 (class 0 OID 16489)
-- Dependencies: 190
-- Data for Name: doc_documentos; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY doc_documentos (id, numero, id_transaccion, id_entidad, fecha, usuario, observacion, estado, id_documento, total) FROM stdin;
\.


--
-- TOC entry 2349 (class 0 OID 16497)
-- Dependencies: 191
-- Data for Name: doc_documentos_detalle; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY doc_documentos_detalle (id, id_documento, linea, id_producto, unidad, id_inventario, cantidad, precio, precio_total, unidad_alterna, cantidad_alterna, factor, descuento, impuesto, observacion, estado) FROM stdin;
\.


--
-- TOC entry 2350 (class 0 OID 16505)
-- Dependencies: 192
-- Data for Name: doc_transacciones; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY doc_transacciones (id, id_entidad, codigo, nombre, numero_inicial, numero_actual, numero_final, tipo, observacion, estado) FROM stdin;
\.


--
-- TOC entry 2351 (class 0 OID 16512)
-- Dependencies: 193
-- Data for Name: inv_bodegas; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY inv_bodegas (id, nombre, observacion, estado, id_entidad) FROM stdin;
\.


--
-- TOC entry 2352 (class 0 OID 16522)
-- Dependencies: 194
-- Data for Name: inv_grupos; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY inv_grupos (id, nombre, estado, observacion, id_grupo) FROM stdin;
\.


--
-- TOC entry 2353 (class 0 OID 16530)
-- Dependencies: 195
-- Data for Name: inv_inventarios; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY inv_inventarios (id, id_bodega, id_tipo_inventario, nombre, observacion, estado) FROM stdin;
\.


--
-- TOC entry 2354 (class 0 OID 16535)
-- Dependencies: 196
-- Data for Name: inv_movimientos; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY inv_movimientos (id, id_transaccion, fecha, id_entidad, usuario, observacion, estado, tipo, id_movimiento, total, id_documento) FROM stdin;
\.


--
-- TOC entry 2355 (class 0 OID 16543)
-- Dependencies: 197
-- Data for Name: inv_movimientos_detalle; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY inv_movimientos_detalle (id, id_movimiento, id_producto, unidad, linea, id_inventario, cantidad, costo, costo_total, unidad_alterna, cantidad_alterna, factor, obseravcion, estado) FROM stdin;
\.


--
-- TOC entry 2356 (class 0 OID 16551)
-- Dependencies: 198
-- Data for Name: inv_permisos_transaccion; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY inv_permisos_transaccion (id_trasaccion, usuario, observacion, estado) FROM stdin;
\.


--
-- TOC entry 2357 (class 0 OID 16554)
-- Dependencies: 199
-- Data for Name: inv_productos; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY inv_productos (id, nombre, codigo_barras, unidad, id_grupo, tipo, estado, observacion, id_entidad) FROM stdin;
\.


--
-- TOC entry 2358 (class 0 OID 16564)
-- Dependencies: 200
-- Data for Name: inv_productos_inventario; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY inv_productos_inventario (id, id_producto, unidad, id_inventario) FROM stdin;
\.


--
-- TOC entry 2359 (class 0 OID 16569)
-- Dependencies: 201
-- Data for Name: inv_propiedad_productos; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY inv_propiedad_productos (id_producto, unidad, propiedad, valor, estado, observacion) FROM stdin;
\.


--
-- TOC entry 2360 (class 0 OID 16577)
-- Dependencies: 202
-- Data for Name: inv_saldos_mensual; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY inv_saldos_mensual (id, id_productos, unidad, id_inventario, saldo, "aÑo", mes, fecha) FROM stdin;
\.


--
-- TOC entry 2361 (class 0 OID 16585)
-- Dependencies: 203
-- Data for Name: inv_tipos_inventario; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY inv_tipos_inventario (id, nombre, observacion, estado) FROM stdin;
\.


--
-- TOC entry 2362 (class 0 OID 16590)
-- Dependencies: 204
-- Data for Name: inv_transacciones; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY inv_transacciones (id, tipo, observacion, estado, id_entidad) FROM stdin;
\.


--
-- TOC entry 2364 (class 0 OID 16603)
-- Dependencies: 206
-- Data for Name: inv_unidad_alternas; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY inv_unidad_alternas (id_producto, unidad, factor, unidad_alterna, estado, observacion) FROM stdin;
\.


--
-- TOC entry 2363 (class 0 OID 16595)
-- Dependencies: 205
-- Data for Name: inv_unidades; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY inv_unidades (unidad, nombre, estado, observacion) FROM stdin;
\.


--
-- TOC entry 2365 (class 0 OID 16611)
-- Dependencies: 207
-- Data for Name: seg_menus; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY seg_menus (id, nombre, url, propiedad, observacion, estado, id_menu) FROM stdin;
\.


--
-- TOC entry 2366 (class 0 OID 16619)
-- Dependencies: 208
-- Data for Name: seg_permisos; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY seg_permisos (id, tipo_permiso, permiso, usuario, id_menu, observacion, estado) FROM stdin;
\.


--
-- TOC entry 2367 (class 0 OID 16627)
-- Dependencies: 209
-- Data for Name: seg_usuarios; Type: TABLE DATA; Schema: public; Owner: postgres
--

COPY seg_usuarios (usuario, tipo, observacion, estado, id_entidad, id) FROM stdin;
jorge	normal	\N	Activo	1	1
\.


--
-- TOC entry 2381 (class 0 OID 0)
-- Dependencies: 210
-- Name: seg_usuarios_id_seq; Type: SEQUENCE SET; Schema: public; Owner: postgres
--

SELECT pg_catalog.setval('seg_usuarios_id_seq', 1, true);


--
-- TOC entry 2141 (class 2606 OID 16504)
-- Name: doc_documentos_detalle doc_documentos_detalle_pk; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY doc_documentos_detalle
    ADD CONSTRAINT doc_documentos_detalle_pk PRIMARY KEY (id);


--
-- TOC entry 2143 (class 2606 OID 16511)
-- Name: doc_transacciones doc_transacciones__un; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY doc_transacciones
    ADD CONSTRAINT doc_transacciones__un UNIQUE (id_entidad, codigo);


--
-- TOC entry 2157 (class 2606 OID 16550)
-- Name: inv_movimientos_detalle inv_movimientos_detalle_pk; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_movimientos_detalle
    ADD CONSTRAINT inv_movimientos_detalle_pk PRIMARY KEY (id);


--
-- TOC entry 2125 (class 2606 OID 16452)
-- Name: adm_entidades pk_adm_entidades; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY adm_entidades
    ADD CONSTRAINT pk_adm_entidades PRIMARY KEY (id);


--
-- TOC entry 2127 (class 2606 OID 16460)
-- Name: adm_localidades pk_adm_localidades; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY adm_localidades
    ADD CONSTRAINT pk_adm_localidades PRIMARY KEY (id);


--
-- TOC entry 2133 (class 2606 OID 16478)
-- Name: adm_propiedad_entidades pk_adm_propiedad_entidades; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY adm_propiedad_entidades
    ADD CONSTRAINT pk_adm_propiedad_entidades PRIMARY KEY (id);


--
-- TOC entry 2129 (class 2606 OID 16468)
-- Name: adm_propiedades pk_adm_propiedades; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY adm_propiedades
    ADD CONSTRAINT pk_adm_propiedades PRIMARY KEY (propiedad);


--
-- TOC entry 2135 (class 2606 OID 16486)
-- Name: adm_tipos pk_adm_tipos; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY adm_tipos
    ADD CONSTRAINT pk_adm_tipos PRIMARY KEY (tipo);


--
-- TOC entry 2139 (class 2606 OID 16496)
-- Name: doc_documentos pk_doc_documentos; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY doc_documentos
    ADD CONSTRAINT pk_doc_documentos PRIMARY KEY (id);


--
-- TOC entry 2145 (class 2606 OID 16509)
-- Name: doc_transacciones pk_doc_transacciones; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY doc_transacciones
    ADD CONSTRAINT pk_doc_transacciones PRIMARY KEY (id);


--
-- TOC entry 2147 (class 2606 OID 16519)
-- Name: inv_bodegas pk_inv_bodegas; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_bodegas
    ADD CONSTRAINT pk_inv_bodegas PRIMARY KEY (id);


--
-- TOC entry 2151 (class 2606 OID 16529)
-- Name: inv_grupos pk_inv_grupos; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_grupos
    ADD CONSTRAINT pk_inv_grupos PRIMARY KEY (id);


--
-- TOC entry 2153 (class 2606 OID 16534)
-- Name: inv_inventarios pk_inv_inventarios; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_inventarios
    ADD CONSTRAINT pk_inv_inventarios PRIMARY KEY (id);


--
-- TOC entry 2155 (class 2606 OID 16542)
-- Name: inv_movimientos pk_inv_movimientos; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_movimientos
    ADD CONSTRAINT pk_inv_movimientos PRIMARY KEY (id);


--
-- TOC entry 2159 (class 2606 OID 16561)
-- Name: inv_productos pk_inv_productos; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_productos
    ADD CONSTRAINT pk_inv_productos PRIMARY KEY (id, unidad);


--
-- TOC entry 2163 (class 2606 OID 16568)
-- Name: inv_productos_inventario pk_inv_productos_inventario; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_productos_inventario
    ADD CONSTRAINT pk_inv_productos_inventario PRIMARY KEY (id);


--
-- TOC entry 2165 (class 2606 OID 16576)
-- Name: inv_propiedad_productos pk_inv_propiedad_productos; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_propiedad_productos
    ADD CONSTRAINT pk_inv_propiedad_productos PRIMARY KEY (id_producto, unidad);


--
-- TOC entry 2167 (class 2606 OID 16584)
-- Name: inv_saldos_mensual pk_inv_saldos_mensual; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_saldos_mensual
    ADD CONSTRAINT pk_inv_saldos_mensual PRIMARY KEY (id);


--
-- TOC entry 2169 (class 2606 OID 16589)
-- Name: inv_tipos_inventario pk_inv_tipos_inventario; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_tipos_inventario
    ADD CONSTRAINT pk_inv_tipos_inventario PRIMARY KEY (id);


--
-- TOC entry 2171 (class 2606 OID 16594)
-- Name: inv_transacciones pk_inv_transacciones; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_transacciones
    ADD CONSTRAINT pk_inv_transacciones PRIMARY KEY (id);


--
-- TOC entry 2175 (class 2606 OID 16610)
-- Name: inv_unidad_alternas pk_inv_unidad_alternas; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_unidad_alternas
    ADD CONSTRAINT pk_inv_unidad_alternas PRIMARY KEY (id_producto, unidad);


--
-- TOC entry 2173 (class 2606 OID 16602)
-- Name: inv_unidades pk_inv_unidades; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_unidades
    ADD CONSTRAINT pk_inv_unidades PRIMARY KEY (unidad);


--
-- TOC entry 2177 (class 2606 OID 16618)
-- Name: seg_menus pk_seg_menus; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY seg_menus
    ADD CONSTRAINT pk_seg_menus PRIMARY KEY (id);


--
-- TOC entry 2179 (class 2606 OID 16626)
-- Name: seg_permisos pk_seg_permisos; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY seg_permisos
    ADD CONSTRAINT pk_seg_permisos PRIMARY KEY (id);


--
-- TOC entry 2181 (class 2606 OID 16634)
-- Name: seg_usuarios pk_seg_usuarios; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY seg_usuarios
    ADD CONSTRAINT pk_seg_usuarios PRIMARY KEY (usuario);


--
-- TOC entry 2131 (class 2606 OID 16470)
-- Name: adm_propiedades uk_adm_propiedades; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY adm_propiedades
    ADD CONSTRAINT uk_adm_propiedades UNIQUE (tabla, propiedad);


--
-- TOC entry 2137 (class 2606 OID 16488)
-- Name: adm_tipos uk_adm_tipos; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY adm_tipos
    ADD CONSTRAINT uk_adm_tipos UNIQUE (tabla, tipo);


--
-- TOC entry 2149 (class 2606 OID 16521)
-- Name: inv_bodegas uk_inv_bodegas; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_bodegas
    ADD CONSTRAINT uk_inv_bodegas UNIQUE (id, id_entidad);


--
-- TOC entry 2161 (class 2606 OID 16563)
-- Name: inv_productos uk_inv_productos; Type: CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_productos
    ADD CONSTRAINT uk_inv_productos UNIQUE (id, id_entidad);


--
-- TOC entry 2182 (class 2606 OID 16866)
-- Name: adm_entidades fk_adm_entidad_entidad; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY adm_entidades
    ADD CONSTRAINT fk_adm_entidad_entidad FOREIGN KEY (id_entidad) REFERENCES adm_entidades(id);


--
-- TOC entry 2183 (class 2606 OID 16871)
-- Name: adm_entidades fk_adm_entidad_localidad; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY adm_entidades
    ADD CONSTRAINT fk_adm_entidad_localidad FOREIGN KEY (id_localidad) REFERENCES adm_localidades(id);


--
-- TOC entry 2184 (class 2606 OID 16645)
-- Name: adm_localidades fk_adm_localidades_localidades; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY adm_localidades
    ADD CONSTRAINT fk_adm_localidades_localidades FOREIGN KEY (id_localidad) REFERENCES adm_localidades(id);


--
-- TOC entry 2185 (class 2606 OID 16650)
-- Name: adm_propiedad_entidades fk_adm_propiedad_entidades; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY adm_propiedad_entidades
    ADD CONSTRAINT fk_adm_propiedad_entidades FOREIGN KEY (id_entidad) REFERENCES adm_entidades(id);


--
-- TOC entry 2186 (class 2606 OID 16655)
-- Name: adm_propiedad_entidades fk_adm_propiedad_entidadesv2; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY adm_propiedad_entidades
    ADD CONSTRAINT fk_adm_propiedad_entidadesv2 FOREIGN KEY (propiedad) REFERENCES adm_propiedades(propiedad);


--
-- TOC entry 2190 (class 2606 OID 16660)
-- Name: doc_documentos_detalle fk_doc_detalle_inventarios; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY doc_documentos_detalle
    ADD CONSTRAINT fk_doc_detalle_inventarios FOREIGN KEY (id_inventario) REFERENCES inv_inventarios(id);


--
-- TOC entry 2191 (class 2606 OID 16665)
-- Name: doc_documentos_detalle fk_doc_detalle_productos; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY doc_documentos_detalle
    ADD CONSTRAINT fk_doc_detalle_productos FOREIGN KEY (id_producto, unidad) REFERENCES inv_productos(id, unidad);


--
-- TOC entry 2187 (class 2606 OID 16670)
-- Name: doc_documentos fk_doc_documentos; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY doc_documentos
    ADD CONSTRAINT fk_doc_documentos FOREIGN KEY (id_documento) REFERENCES doc_documentos(id);


--
-- TOC entry 2192 (class 2606 OID 16675)
-- Name: doc_documentos_detalle fk_doc_documentos_detalle; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY doc_documentos_detalle
    ADD CONSTRAINT fk_doc_documentos_detalle FOREIGN KEY (id_documento) REFERENCES doc_documentos(id);


--
-- TOC entry 2188 (class 2606 OID 16680)
-- Name: doc_documentos fk_doc_documentos_entidades; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY doc_documentos
    ADD CONSTRAINT fk_doc_documentos_entidades FOREIGN KEY (id_entidad) REFERENCES adm_entidades(id);


--
-- TOC entry 2189 (class 2606 OID 16685)
-- Name: doc_documentos fk_doc_documentos_transacciones; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY doc_documentos
    ADD CONSTRAINT fk_doc_documentos_transacciones FOREIGN KEY (id_transaccion) REFERENCES doc_transacciones(id);


--
-- TOC entry 2193 (class 2606 OID 16690)
-- Name: doc_transacciones fk_doc_transaccion_entidad; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY doc_transacciones
    ADD CONSTRAINT fk_doc_transaccion_entidad FOREIGN KEY (id_entidad) REFERENCES adm_entidades(id);


--
-- TOC entry 2194 (class 2606 OID 16695)
-- Name: inv_bodegas fk_inv_bodega_entidad; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_bodegas
    ADD CONSTRAINT fk_inv_bodega_entidad FOREIGN KEY (id_entidad) REFERENCES adm_entidades(id);


--
-- TOC entry 2203 (class 2606 OID 16700)
-- Name: inv_movimientos_detalle fk_inv_detalle_inventarios; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_movimientos_detalle
    ADD CONSTRAINT fk_inv_detalle_inventarios FOREIGN KEY (id_inventario) REFERENCES inv_inventarios(id);


--
-- TOC entry 2204 (class 2606 OID 16705)
-- Name: inv_movimientos_detalle fk_inv_detalle_productos; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_movimientos_detalle
    ADD CONSTRAINT fk_inv_detalle_productos FOREIGN KEY (id_producto, unidad) REFERENCES inv_productos(id, unidad);


--
-- TOC entry 2195 (class 2606 OID 16710)
-- Name: inv_grupos fk_inv_grupos; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_grupos
    ADD CONSTRAINT fk_inv_grupos FOREIGN KEY (id_grupo) REFERENCES inv_grupos(id);


--
-- TOC entry 2196 (class 2606 OID 16720)
-- Name: inv_inventarios fk_inv_inventario_bodega; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_inventarios
    ADD CONSTRAINT fk_inv_inventario_bodega FOREIGN KEY (id_bodega) REFERENCES inv_bodegas(id);


--
-- TOC entry 2212 (class 2606 OID 16725)
-- Name: inv_productos_inventario fk_inv_inventario_inventario; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_productos_inventario
    ADD CONSTRAINT fk_inv_inventario_inventario FOREIGN KEY (id_inventario) REFERENCES inv_inventarios(id);


--
-- TOC entry 2213 (class 2606 OID 16730)
-- Name: inv_productos_inventario fk_inv_inventario_producto; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_productos_inventario
    ADD CONSTRAINT fk_inv_inventario_producto FOREIGN KEY (id_producto, unidad) REFERENCES inv_productos(id, unidad);


--
-- TOC entry 2197 (class 2606 OID 16735)
-- Name: inv_inventarios fk_inv_inventario_tipo; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_inventarios
    ADD CONSTRAINT fk_inv_inventario_tipo FOREIGN KEY (id_tipo_inventario) REFERENCES inv_tipos_inventario(id);


--
-- TOC entry 2216 (class 2606 OID 16715)
-- Name: inv_saldos_mensual fk_inv_inventarios; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_saldos_mensual
    ADD CONSTRAINT fk_inv_inventarios FOREIGN KEY (id_inventario) REFERENCES inv_inventarios(id);


--
-- TOC entry 2205 (class 2606 OID 16740)
-- Name: inv_movimientos_detalle fk_inv_movimiento_detalle; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_movimientos_detalle
    ADD CONSTRAINT fk_inv_movimiento_detalle FOREIGN KEY (id_movimiento) REFERENCES inv_movimientos(id);


--
-- TOC entry 2198 (class 2606 OID 16745)
-- Name: inv_movimientos fk_inv_movimiento_documento; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_movimientos
    ADD CONSTRAINT fk_inv_movimiento_documento FOREIGN KEY (id_documento) REFERENCES doc_documentos(id);


--
-- TOC entry 2199 (class 2606 OID 16750)
-- Name: inv_movimientos fk_inv_movimiento_entidad; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_movimientos
    ADD CONSTRAINT fk_inv_movimiento_entidad FOREIGN KEY (id_entidad) REFERENCES adm_entidades(id);


--
-- TOC entry 2200 (class 2606 OID 16755)
-- Name: inv_movimientos fk_inv_movimiento_movimiento; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_movimientos
    ADD CONSTRAINT fk_inv_movimiento_movimiento FOREIGN KEY (id_movimiento) REFERENCES inv_movimientos(id);


--
-- TOC entry 2201 (class 2606 OID 16760)
-- Name: inv_movimientos fk_inv_movimiento_transaccion; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_movimientos
    ADD CONSTRAINT fk_inv_movimiento_transaccion FOREIGN KEY (id_transaccion) REFERENCES inv_transacciones(id);


--
-- TOC entry 2202 (class 2606 OID 16765)
-- Name: inv_movimientos fk_inv_movimiento_usuario; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_movimientos
    ADD CONSTRAINT fk_inv_movimiento_usuario FOREIGN KEY (usuario) REFERENCES seg_usuarios(usuario);


--
-- TOC entry 2206 (class 2606 OID 16770)
-- Name: inv_permisos_transaccion fk_inv_permisos_transaccion; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_permisos_transaccion
    ADD CONSTRAINT fk_inv_permisos_transaccion FOREIGN KEY (id_trasaccion) REFERENCES inv_transacciones(id);


--
-- TOC entry 2207 (class 2606 OID 16775)
-- Name: inv_permisos_transaccion fk_inv_permisos_usuarios; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_permisos_transaccion
    ADD CONSTRAINT fk_inv_permisos_usuarios FOREIGN KEY (usuario) REFERENCES seg_usuarios(usuario);


--
-- TOC entry 2217 (class 2606 OID 16780)
-- Name: inv_saldos_mensual fk_inv_productos; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_saldos_mensual
    ADD CONSTRAINT fk_inv_productos FOREIGN KEY (id_productos, unidad) REFERENCES inv_productos(id, unidad);


--
-- TOC entry 2208 (class 2606 OID 16785)
-- Name: inv_productos fk_inv_productos_adm_entidades; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_productos
    ADD CONSTRAINT fk_inv_productos_adm_entidades FOREIGN KEY (id_entidad) REFERENCES adm_entidades(id);


--
-- TOC entry 2209 (class 2606 OID 16790)
-- Name: inv_productos fk_inv_productos_adm_tipos; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_productos
    ADD CONSTRAINT fk_inv_productos_adm_tipos FOREIGN KEY (tipo) REFERENCES adm_tipos(tipo);


--
-- TOC entry 2210 (class 2606 OID 16795)
-- Name: inv_productos fk_inv_productos_inv_grupos; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_productos
    ADD CONSTRAINT fk_inv_productos_inv_grupos FOREIGN KEY (id_grupo) REFERENCES inv_grupos(id);


--
-- TOC entry 2211 (class 2606 OID 16800)
-- Name: inv_productos fk_inv_productos_inv_unidades; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_productos
    ADD CONSTRAINT fk_inv_productos_inv_unidades FOREIGN KEY (unidad) REFERENCES inv_unidades(unidad);


--
-- TOC entry 2214 (class 2606 OID 16805)
-- Name: inv_propiedad_productos fk_inv_propiedad_productos; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_propiedad_productos
    ADD CONSTRAINT fk_inv_propiedad_productos FOREIGN KEY (id_producto, unidad) REFERENCES inv_productos(id, unidad);


--
-- TOC entry 2215 (class 2606 OID 16810)
-- Name: inv_propiedad_productos fk_inv_propiedad_productosv2; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_propiedad_productos
    ADD CONSTRAINT fk_inv_propiedad_productosv2 FOREIGN KEY (propiedad) REFERENCES adm_propiedades(propiedad);


--
-- TOC entry 2218 (class 2606 OID 16815)
-- Name: inv_transacciones fk_inv_transaccion_entidad; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_transacciones
    ADD CONSTRAINT fk_inv_transaccion_entidad FOREIGN KEY (id_entidad) REFERENCES adm_entidades(id);


--
-- TOC entry 2221 (class 2606 OID 16820)
-- Name: seg_menus fk_seg_menus_seg_menus; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY seg_menus
    ADD CONSTRAINT fk_seg_menus_seg_menus FOREIGN KEY (id_menu) REFERENCES seg_menus(id);


--
-- TOC entry 2222 (class 2606 OID 16825)
-- Name: seg_permisos fk_seg_permisos_adm_tipos; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY seg_permisos
    ADD CONSTRAINT fk_seg_permisos_adm_tipos FOREIGN KEY (tipo_permiso) REFERENCES adm_tipos(tipo);


--
-- TOC entry 2223 (class 2606 OID 16830)
-- Name: seg_permisos fk_seg_permisos_seg_menus; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY seg_permisos
    ADD CONSTRAINT fk_seg_permisos_seg_menus FOREIGN KEY (id_menu) REFERENCES seg_menus(id);


--
-- TOC entry 2224 (class 2606 OID 16835)
-- Name: seg_permisos fk_seg_permisos_usuarios; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY seg_permisos
    ADD CONSTRAINT fk_seg_permisos_usuarios FOREIGN KEY (usuario) REFERENCES seg_usuarios(usuario);


--
-- TOC entry 2225 (class 2606 OID 16840)
-- Name: seg_usuarios fk_seg_usuarios_entidades; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY seg_usuarios
    ADD CONSTRAINT fk_seg_usuarios_entidades FOREIGN KEY (id_entidad) REFERENCES adm_entidades(id);


--
-- TOC entry 2219 (class 2606 OID 16845)
-- Name: inv_unidad_alternas fk_unidad_alternas_productos; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_unidad_alternas
    ADD CONSTRAINT fk_unidad_alternas_productos FOREIGN KEY (id_producto, unidad) REFERENCES inv_productos(id, unidad);


--
-- TOC entry 2220 (class 2606 OID 16850)
-- Name: inv_unidad_alternas fk_unidad_alternas_unidades; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY inv_unidad_alternas
    ADD CONSTRAINT fk_unidad_alternas_unidades FOREIGN KEY (unidad_alterna) REFERENCES inv_unidades(unidad);


-- Completed on 2017-01-04 18:38:46 ECT

--
-- PostgreSQL database dump complete
--

\connect template1

SET default_transaction_read_only = off;

--
-- PostgreSQL database dump
--

-- Dumped from database version 9.6.1
-- Dumped by pg_dump version 9.6.1

-- Started on 2017-01-04 18:38:46 ECT

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;
SET row_security = off;

--
-- TOC entry 2122 (class 1262 OID 1)
-- Dependencies: 2121
-- Name: template1; Type: COMMENT; Schema: -; Owner: postgres
--

COMMENT ON DATABASE template1 IS 'default template for new databases';


--
-- TOC entry 1 (class 3079 OID 12394)
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- TOC entry 2124 (class 0 OID 0)
-- Dependencies: 1
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


-- Completed on 2017-01-04 18:38:46 ECT

--
-- PostgreSQL database dump complete
--

-- Completed on 2017-01-04 18:38:46 ECT

--
-- PostgreSQL database cluster dump complete
--

