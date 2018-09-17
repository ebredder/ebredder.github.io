why=2;
ex=2;
origin=0;

module incPlane(height=why,length=ex){
    polygon(points=[[origin,origin],[origin,height],[length,origin]]);
}


