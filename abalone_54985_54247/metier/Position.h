#ifndef _POSITION_H
#define _POSITION_H

#include "Direction.h"

class Position {
public: 
    
/*!
 * \brief Constructor of the Position class.
 *
 * \param x the value of the x axis.
 * \param y the value of the y axis.
 * \param z the value of the z axis.
 *
 * \throws std::invalid_argument if the sum of the attributes is different than zero.
 */
Position(int x, int y, int z);
    
/*!
 * \brief Copy constructor of the Position class.
 *
 * \param pos the position that will provide the values.
 */
Position(Position& pos);
    
/*!
 * \brief  Comparison of equality between two positions.
 *
 * \param pos the position to compare.
 *
 * \return true if the position share the same value, false otherwise.
 */
inline bool operator==(Position pos);
    
/*!
 * \brief  Gets the next position given a direction.
 *
 * \param dir the direction that will be used to determine the next case.
 *
 * \return the position next to the current case, based on the  given direction.
 *
 */
Position getNext(Direction dir);
    
/*!
 * \brief  Getter of the x value.
 *
 * \return the x value.
 */
inline int getX() const;
    
/*!
 * \brief  Getter of the xyvalue.
 *
 * \return the y value.
 */
inline int getY() const;
    
/*!
 * \brief  Getter of the y value.
 *
 * \return the y value.
 */
inline int getZ() const;

private: 
/*!
* \brief  the value of the x axis.
*/
int x;

/*!
* \brief  the value of the y axis.
*/
int y;

/*!
* \brief  the value of the z axis.
*/
int z;
};

#endif //_POSITION_H
