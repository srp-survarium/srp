void __thiscall btDiscreteDynamicsWorld::addVehicle(btDiscreteDynamicsWorld *this, btActionInterface *vehicle)
{
  this->addAction(this, vehicle);
}
