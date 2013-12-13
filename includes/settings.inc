<?php

/**
 * settings form's callback for Drupal's form API
 *
 * @return Array
 * @author Giorgi Jibladze
 */
function ipay_settings_form() {
	$form = array();
	$form['ipay_username'] = array(
	 '#type'          => 'textfield',
	 '#title'         => t('Username'),
	 '#default_value' => variable_get('ipay_username', ''),
	 '#description'   => t("for iPay service"),
	 '#required'      => TRUE,
	);

	$form['ipay_password'] = array(
	 '#type'          => 'textfield',
	 '#title'         => t('Password'),
	 '#default_value' => variable_get('ipay_password', ''),
	 '#description'   => t("for iPay service"),
	 '#required'      => TRUE,
	);
	
	$form['ipay_secret_key'] = array(
	 '#type'          => 'textfield',
	 '#title'         => t('Secret Key'),
	 '#default_value' => variable_get('ipay_secret_key', ''),
	 '#description'   => t("for hashing parameters"),
	 '#required'      => TRUE,
	);
	
	$form['ipay_host'] = array(
	 '#type'          => 'textfield',
	 '#title'         => t('iPay\'s servers IP Address(es)'),
	 '#default_value' => variable_get('ipay_host', ''),
	 '#description'   => t("specify range with dash"),
	 '#required'      => FALSE,
	);
	

	return system_settings_form($form);
}
