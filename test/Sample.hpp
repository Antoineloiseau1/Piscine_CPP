/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoine <antoine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:48:12 by antoine           #+#    #+#             */
/*   Updated: 2023/02/15 14:51:37 by antoine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAMPLE_H
# define SAMPLE_H

# include <string>

class	Sample
{
	public:

		char		letter;
		int			number;
		std::string	message;
		
		Sample(char c, int i, std::string str);
		~Sample(void);

		void aff_string(void);
};


#endif
