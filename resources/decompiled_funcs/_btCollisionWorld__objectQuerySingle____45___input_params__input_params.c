void __userpurge btCollisionWorld::objectQuerySingle_::_45_::input_params::input_params(
        btCollisionWorld::objectQuerySingle::__l45::input_params *this@<ecx>,
        btCollisionWorld::objectQuerySingle::__l45::input_params **a2@<eax>,
        const btTransform *_castShape,
        btCollisionWorld::objectQuerySingle::__l45::input_params *_convexFromTrans,
        btCollisionObject *_convexToTrans,
        const btCollisionShape *_collisionObject,
        const btTransform *_collisionShape,
        btCollisionWorld::ConvexResultCallback *_colObjWorldTransform,
        btCollisionWorld::objectQuerySingle::__l45::input_params *_resultCallback,
        float _allowedPenetration)
{
  *a2 = this;
  a2[1] = (btCollisionWorld::objectQuerySingle::__l45::input_params *)_castShape;
  a2[2] = _convexFromTrans;
  a2[3] = (btCollisionWorld::objectQuerySingle::__l45::input_params *)_convexToTrans;
  a2[4] = (btCollisionWorld::objectQuerySingle::__l45::input_params *)_collisionObject;
  a2[5] = (btCollisionWorld::objectQuerySingle::__l45::input_params *)_collisionShape;
  a2[6] = (btCollisionWorld::objectQuerySingle::__l45::input_params *)_colObjWorldTransform;
  a2[7] = _resultCallback;
}
