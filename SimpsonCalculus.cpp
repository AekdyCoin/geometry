/*
 * [l,  m , r ]
 * sl = f(l), sm = f(m), sr = f(r)
 * the ans must /=6.0
 */

db rsimp( db l,db m, db r, db sl, db sm, db sr,db tot){ //ans = ** / 6.0
    db m1 = (l + m) * 0.5, m2 = (m + r) * 0.5;
    db s0 = f( m1), s2 = f( m2);
    db gl = (sl + sm + s0 + s0 + s0 + s0)*(m-l),    gr = (sm + sr + s2 + s2 + s2 + s2)*(r-m);
    if( fs(gl + gr - tot) < EPS) return gl + gr;
	return rsimp( l, m1, m, sl, s0, sm, gl) + rsimp( m, m2,r, sm, s2, sr, gr);}
