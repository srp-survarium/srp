void __thiscall btDiscreteDynamicsWorld::addCharacter(btDiscreteDynamicsWorld *this, btActionInterface *vehicle)
{
  this->addAction(this, vehicle);
}
